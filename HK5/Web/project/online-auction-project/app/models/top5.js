const db = require('../utils/db');

module.exports = {
    time: async () => {
        const sql = `select A.*, B.first as bname
            from (select distinct item.*, category.cat, count(bid.id) as n, max(bid.cost) as price from item left join bid on item.id = bid.id join category on category.sub = item.subcat where item.end > now() group by item.id order by end limit 5) 
            as A
            left join (select user.first, user.id, bid.cost, bid.id as i from user join bid on bid.user = user.id and bid.allow = '1')
            as B
            on A.price = B.cost and A.id = B.i`;
        const cats = await db.load(sql);

        return cats;
    },
    bid: async () => {
        const sql = `select A.*, B.first as bname
            from (select item.*, category.cat, count(bid.id) as n, max(bid.cost) as price from item join bid on item.id = bid.id join category on category.sub = item.subcat group by item.id order by count(bid.id) desc limit 5) 
            as A
            left join (select user.first, user.id, bid.cost, bid.id as i from user join bid on bid.user = user.id and bid.allow = '1')
            as B
            on A.price = B.cost and A.id = B.i`;
        const cats = await db.load(sql);

        return cats;
    },
    cost: async () => {
        const sql = `select A.*, B.first as bname
            from (select item.*, category.cat, count(bid.id) as n, max(bid.cost) as price from item left join bid on item.id = bid.id join category on category.sub = item.subcat where item.end > now() group by item.id order by if(max(bid.cost), max(bid.cost), item.cost) desc limit 5) 
            as A
            left join (select user.first, user.id, bid.cost, bid.id as i from user join bid on bid.user = user.id and bid.allow = '1')
            as B
            on A.price = B.cost and A.id = B.i`;
        const cats = await db.load(sql);

        return cats;
    }
};