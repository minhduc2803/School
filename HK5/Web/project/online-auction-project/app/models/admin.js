const db = require('../utils/db');

module.exports = {
    user: async (id_tag, table) => {
        var sql = ``;
        if(id_tag == 3){
            sql = `select * from ${table}`;
        }
        else{
        sql = `select * from ${table} where type = ${id_tag}`;
        }
        const user = await db.load(sql);
        return user;
    },
    mote: async (id,type) => {
        const result = await db.mote(id,type);
        return result;
    },
    category: async () => {
        const sql = `select distinct cat from category`;
        const category = await db.load(sql);
        return category;
    },
    subcat: async (cat) => {
        const sql = `select * from category where cat = '${cat}'`;
        const subcat = await db.load(sql);
        return subcat;
    },
    products: async (sub) => {
        const sql = `select item.*, user.name as seller, category.cat
        from 
        (item left join user on (item.seller = user.id))
        left join category on (item.subcat = category.sub) 
        where item.subcat = '${sub}'`;
        const products = await db.load(sql);
        return products;
    },
    product: async (id) => {
        const sql = `select * from item where id = '${id}'`;
        const product = await db.load(sql);
        return product;
    },
    first: async () => {
        const sql = `select * from category limit 1`;
        const firstrow = await db.load(sql);
        return firstrow;
    },
    addsub: async (sub,cat) => {
        const result = await db.addsub(sub,cat);
        return result;
    }
};
