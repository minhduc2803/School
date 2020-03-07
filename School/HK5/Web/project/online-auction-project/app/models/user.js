const db = require('../utils/db');

module.exports = {
    byUser: async (username) => {
        const sql = `select * from user where username = '${username}'`;
        const rs = await db.load(sql);

        return rs[0];
    },
    byEmail: async (email) => {
        const sql = `select * from user where email = '${email}'`;
        const rs = await db.load(sql);

        return rs[0];
    },
    byId: async (id) => {
        const sql = `select * from user where id = '${id}'`;
        const rs = await db.load(sql);

        return rs[0];
    }
};