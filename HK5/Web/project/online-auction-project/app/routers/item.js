const express = require('express');
const router = express.Router();

const mCat = require('../models/category');
const mItem = require('../models/item');
const mWL = require('../models/wl');

router.get('/:id', async (req, res) => {
    const cats = await mCat.cat();
    const subs = await mCat.all();
    const id = parseInt(req.params.id);
    let user;
    if (req.user)
        user = parseInt(req.user.id);

    const item = await mItem.one(id, user);
    const items = await mItem.all(id, user);
    const his = await mItem.his(id);

    let wl;
    if (req.user)
        wl = await mWL.all(user);

    res.render('home', {
        title: item.name,
        cats: cats,
        subs: subs,
        layout: 'item',
        item: item,
        items: items,
        catn: item.cat,
        subn: item.subcat,
        user: req.user,
        wl: wl,
        his: his
    });
});

module.exports = router;