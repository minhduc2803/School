const express = require('express');
const router = express.Router();

const mCat = require('../models/category');
const mSearch = require('../models/search');

router.get('/', async (req, res) => {
    const cats = await mCat.cat();
    const subs = await mCat.all();
    const page = parseInt(req.query.page) || 1;
    const sort = parseInt(req.query.sort) || 0;

    let list;
    if (req.query.cat != 'All Categories')
        list = await mSearch.cat(req.query.keyword, req.query.cat, page, sort);
    else
        list = await mSearch.all(req.query.keyword, page, sort);

    const pages = [];

    for (i = 0; i < list.total; ++i)
        pages[i] = {
            value: i + 1,
            active: (i + 1) === page
        };

    const navs = {};
    if (page > 1)
        navs.prev = page - 1;
    if (page < list.total)
        navs.next = page + 1;

    res.render('home', {
        title: 'Search: \'' + req.query.keyword + '\'',
        cats: cats,
        subs: subs,
        layout: 'list',
        items: list.items,
        pages: pages,
        navs: navs,
        catn: req.query.cat,
        keyword: req.query.keyword,
        user: req.user
    });
});

module.exports = router;