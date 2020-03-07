const db = require('../utils/db');

module.exports = {
    one: async (id, user) => {
        const sql = `select A.*, B.first as bname, B.rate as brate, C.first as sname, C.rate as srate, D.user as wl, E.id as status
        from (select item.*, category.cat, count(bid.id) as n, max(bid.cost) as price from item left join bid on item.id = bid.id join category on category.sub = item.subcat where item.id = '${id}' group by item.id) 
        as A
        left join (select user.first, avg(review.rate) as rate, bid.cost from user left join review on review.id = user.id join bid on bid.user = user.id and bid.allow = '1' group by user.id)
        as B
        on A.price = B.cost
        left join (select user.id, user.first, avg(review.rate) as rate from user left join review on review.id = user.id group by user.id)
        as C
        on C.id = A.seller
        left join (select * from watchlist)
        as D
        on D.item = A.id and D.user = '${user}'
        left join (select id from won)
        as E
        on E.id = A.id`;
        const item = await db.load(sql);

        return item[0];
    },
    all: async (id, user) => {
        const sql = `select A.*, B.first as bname, C.user as wl
            from (select item.*, count(bid.id) as n, max(bid.cost) as price from item left join bid on item.id = bid.id join category on category.sub = item.subcat where item.id != ${id} and category.cat in (select category.cat from category join item on item.subcat = category.sub where item.id = ${id}) group by item.id limit 5) 
            as A
            left join (select user.first, user.id, bid.cost, bid.id as i from user join bid on bid.user = user.id and bid.allow = '1')
            as B
            on A.price = B.cost and A.id = B.i
            left join (select * from watchlist)
            as C
            on C.item = A.id and C.user = '${user}'`;
        const item = await db.load(sql);

        return item;
    },
    his: async (id) => {
        const sql = `select A.*, B.first
        from (select * from bid where id = '${id}')
        as A
        left join (select first, id from user)
        as B
        on B.id = A.user`;
        const item = await db.load(sql);

        return item;
    },
    won: async (user) => {
        const sql = `select item.id, item.name, won.cost, won.create
        from item join won on won.id = item.id
        where won.user='${user}'`;
        const item = await db.load(sql);

        return item;
    },
    bid: async (user) => {
        const sql = `select item.id, item.name, bid.cost, bid.create
        from item join bid on bid.id = bid.id
        where bid.user='${user}'`;
        const item = await db.load(sql);

        return item;
    }
};