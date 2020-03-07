const db = require('../utils/db');

module.exports = {
    addWL: async (user, item) => {
        let sql = `select * from watchlist where user = ${user} and item = ${item}`;
        const ck = await db.load(sql);

        if (ck && ck[0])
            return null;

        const data = {
            user: user,
            item: item
        }
        const rs = await db.add('watchlist', data);

        if (rs) {
            sql = `select * from item where id = ${item}`;
            const i = await db.load(sql);

            return i[0];
        }

        return null;
    },
    rmWL: async (user, item) => {
        let sql = `delete from watchlist where user = ${user} and item = ${item}`;
        const rs = await db.load(sql);

        if (rs) {
            sql = `select * from item where id = ${item}`;
            const i = await db.load(sql);

            return i[0];
        }

        return null;
    },
    all: async (user) => {
        const sql = `select item.* from item left join watchlist on item.id = watchlist.item where watchlist.user = ${user}`;
        const rs = await db.load(sql);

        return rs;
    }
};