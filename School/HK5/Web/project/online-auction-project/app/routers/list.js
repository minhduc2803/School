const express = require('express');
const router = express.Router();

const mCat = require('../models/category');
const mList = require('../models/list');
const mWL = require('../models/wl');

router.get('/:cat', async (req, res) => {
    const cats = await mCat.cat();
    const subs = await mCat.all();
    const page = parseInt(req.query.page) || 1;
    let user;
    if (req.user)
        user = parseInt(req.user.id);

    const sort = parseInt(req.query.sort) || 0;
    const list = await mList.cat(req.params.cat, page, user, sort);
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

    let wl;
    if (req.user)
        wl = await mWL.all(user);

    res.render('home', {
        title: req.params.cat,
        cats: cats,
        subs: subs,
        layout: 'list',
        items: list.items,
        pages: pages,
        navs: navs,
        catn: req.params.cat,
        user: req.user,
        wl: wl
    });
});

router.get('/:cat/:sub', async (req, res) => {
    const cats = await mCat.cat();
    const subs = await mCat.all();
    const page = parseInt(req.query.page) || 1;
    let user;
    if (req.user)
        user = parseInt(req.user.id);

    const sort = parseInt(req.query.sort) || 0;
    const list = await mList.sub(req.params.sub, page, user, sort);
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

    let wl;
    if (req.user)
        wl = await mWL.all(user);

    res.render('home', {
        title: req.params.sub,
        cats: cats,
        subs: subs,
        layout: 'list',
        items: list.items,
        pages: pages,
        navs: navs,
        catn: req.params.cat,
        subn: req.params.sub,
        user: req.user,
        wl: wl
    });
});

module.exports = router;