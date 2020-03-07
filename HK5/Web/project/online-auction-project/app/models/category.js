const db = require('../utils/db');

module.exports = {
    cat: async () => {
        const sql = `select distinct cat from category`;
        const cats = await db.load(sql);

        return cats;
    },
    all: async () => {
        const sql = `select * from category`;
        const cats = await db.load(sql);

        return cats;
    }
};