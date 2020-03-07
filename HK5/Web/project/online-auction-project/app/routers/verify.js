const express = require('express');
const router = express.Router();

const mCat = require('../models/category');
const mUser = require('../models/user');
const mLoad = require('../models/load');

router.get('/', async (req, res) => {
    if (!req.query.id) {
        res.redirect('/');
        return;
    }

    const id = parseInt(req.query.id);
    const user = await mUser.byId(id);
    if (!user) {
        res.redirect('/');
        return;
    }

    const cats = await mCat.cat();
    const subs = await mCat.all();

    res.render('home', {
        css: ['style'],
        js: ['/javascripts/script.js', 'https://www.google.com/recaptcha/api.js'],
        contain: 'auth/verify',
        title: 'Verify',
        cats: cats,
        subs: subs,
        id: id,
        failed: parseInt(req.query.failed),
        verified: parseInt(req.query.verified),
        login: req.isAuthenticated()
    });
});

router.post('/', async (req, res) => {

    const id = parseInt(req.body.id);
    const otp = req.body.otp;
    const user = await mUser.byId(id);

    if (!user) {

        res.redirect('/');
        return;
    }

    if (otp == user.otp) {

        const rs = await mLoad.all(`update user set verified='1' where id='${id}'`);

        if (!rs) {
            res.send('Verify failed! Try again.');
            return;
        }

        res.send('Verify success!');
        return;
    }

    res.send('Wrong code!');
});

module.exports = router;