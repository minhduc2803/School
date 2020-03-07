const db = require('../utils/db');

module.exports = {
    all: async (sql) => {
        const rs = await db.load(sql);

        return rs;
    }
};