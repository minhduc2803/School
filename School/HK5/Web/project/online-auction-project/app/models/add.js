const db = require('../utils/db');

module.exports = {
    all: async (table, data) => {
        const rs = await db.add(table, data);

        return rs;
    }
};