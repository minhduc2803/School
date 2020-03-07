const db = require('../utils/db');

module.exports = {
    byUser: async (username) => {
        const sql = `select * from admin where username = '${username}'`;
        const rs = await db.load(sql);

        return rs[0];
    },
    
    byId: async (id) => {
        const sql = `select * from admin where id = '${id}'`;
        const rs = await db.load(sql);

        return rs[0];
    }
};