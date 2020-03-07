const db = require('../db.js');
const tbName = 'products';

module.exports = {
    allByCatId: async id => {
        const sql = ` SELECT * FROM ${tbName} WHERE CatID=${id}`;
        const rows = await db.load(sql);
        return rows;
    },
    ById: async id => {
        const sql = ` SELECT * FROM ${tbName} WHERE ProID=${id}`;
        const rows = await db.load(sql);
        return rows;
    },
};