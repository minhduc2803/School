const db = require('../utils/db');
const limit = 6;

module.exports = {
    cat: async (catn, page, user, sort) => {

        let sql = `select count(*) as total from item join category on item.subcat = category.sub where category.cat = '${catn}'`;
        const total = await db.load(sql);

        let s = '';
        if (sort) {
            if (sort == 1)
                s = 'order by count(bid.id) desc';
            else if (sort == 2)
                s = 'order by end';
            else if (sort == 3)
                s = 'order by if(max(bid.cost), max(bid.cost), item.cost)';
            else
                s = 'order by if(max(bid.cost), max(bid.cost), item.cost) desc';
        }

        const offset = (page - 1) * limit;
        sql = `select A.*, B.first as bname, C.user as wl
        from (select item.*, count(bid.id) as n, max(bid.cost) as price from item left join bid on item.id = bid.id join category on category.sub = item.subcat where category.cat = '${catn}' group by item.id ${s} limit ${limit} offset ${offset}) 
        as A
        left join (select user.first, user.id, bid.cost, bid.id as i from user join bid on bid.user = user.id and bid.allow = '1')
            as B
            on A.price = B.cost and A.id = B.i
        left join (select * from watchlist)
        as C
        on C.item = A.id and C.user = '${user}'`;
        const items = await db.load(sql);

        return {
            pages: Math.floor(total[0].total / limit) + 1,
            items: items
        };
    },
    sub: async (subn, page, user, sort) => {

        let sql = `select count(*) as total from item where subcat = '${subn}'`;
        const total = await db.load(sql);

        let s = '';
        if (sort) {
            if (sort == 1)
                s = 'order by count(bid.id) desc';
            else if (sort == 2)
                s = 'order by end';
            else if (sort == 3)
                s = 'order by if(max(bid.cost), max(bid.cost), item.cost)';
            else
                s = 'order by if(max(bid.cost), max(bid.cost), item.cost) desc';
        }

        const offset = (page - 1) * limit;
        sql = `select A.*, B.first as bname, C.user as wl
            from (select item.*, count(bid.id) as n, max(bid.cost) as price from item left join bid on item.id = bid.id join category on category.sub = item.subcat where category.sub = '${subn}' group by item.id ${s} limit ${limit} offset ${offset}) 
            as A
            left join (select user.first, user.id, bid.cost, bid.id as i from user join bid on bid.user = user.id and bid.allow = '1')
            as B
            on A.price = B.cost and A.id = B.i
            left join (select * from watchlist)
            as C
            on C.item = A.id and C.user = '${user}'`;
        const items = await db.load(sql);

        return {
            pages: Math.floor(total[0].total / limit) + 1,
            items: items
        };
    }
};