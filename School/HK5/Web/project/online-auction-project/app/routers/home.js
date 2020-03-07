const express = require('express');
const router = express.Router();

const mCat = require('../models/category');
const mTop5 = require('../models/top5');

router.get('/', async (req, res) => {
    const cats = await mCat.cat();
    const subs = await mCat.all();
    const times = await mTop5.time();
    const bids = await mTop5.bid();
    const costs = await mTop5.cost();

    res.render('home', {
        css: ['style'],
        js: ['/javascripts/script.js'],
        contain: 'home/contain',
        title: 'Home',
        cats: cats,
        subs: subs,
        times: times,
        bids: bids,
        costs: costs,
        user: req.user
    });
});

module.exports = router;