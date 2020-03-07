const express = require('express');
const router = express.Router();
const bcrypt = require('bcryptjs');
const saltRounds = 10;

const mAdd = require('../models/add');
const mLoad = require('../models/load');
const mWL = require('../models/wl');

router.get('/profile', (req, res) => {

    if (!req.user) {
        res.redirect('/login');
        return;
    }

    res.render('home', {
        css: ['style'],
        js: ['/javascripts/script.js', 'https://www.google.com/recaptcha/api.js'],
        contain: 'acc/profile',
        title: 'profile',
        user: req.user
    });
})

router.get('/review', async (req, res) => {

    if (!req.user) {
        res.redirect('/login');
        return;
    }

    const sql = `select user.username as username, review.text, review.rate, review.date from review left join user on user.id = review.user where review.toUser = '${req.user.id}'`;
    const rs = await mLoad.all(sql);

    let avg = 0;
    for (i = 0; i < rs.length; ++i)
        avg += rs[i].rate;
    if (avg)
        avg /= rs.length;

    res.render('home', {
        css: ['style'],
        js: ['/javascripts/script.js'],
        contain: 'acc/review',
        title: 'review',
        user: req.user,
        rs: rs,
        avg: avg,
        flag: rs[0]
    })
})

router.get('/watchlist', async (req, res) => {

    if (!req.user) {
        res.redirect('/login');
        return;
    }

    const rs = await mWL.all(req.user.id);

    res.render('home', {
        css: ['style'],
        js: ['/javascripts/script.js'],
        contain: 'acc/watchlist',
        title: 'watchlist',
        user: req.user,
        rs: rs,
        flag: rs[0]
    })
})

router.get('/bid', async (req, res) => {
    if (!req.user) {
        res.redirect('/login');
        return;
    }

    const rs = await mLoad.all(`select * from bid join item on item.id = bid.id where user='${req.user.id}'`);

    res.render('home', {
        css: ['style'],
        js: ['/javascripts/script.js'],
        contain: 'acc/bid',
        title: 'bid',
        user: req.user,
        rs: rs,
        flag: rs[0]
    })
})

router.get('/won', async (req, res) => {
    if (!req.user) {
        res.redirect('/login');
        return;
    }

    const rs = await mLoad.all(`select item.*, won.date, review.rate, review.text as rvtext, review.date as rvdate from won join item on item.id = won.id left join review on review.id = item.id and review.user = won.user where won.user='${req.user.id}'`);

    res.render('home', {
        css: ['style'],
        js: ['/javascripts/script.js'],
        contain: 'acc/won',
        title: 'won',
        user: req.user,
        rs: rs,
        flag: rs[0]
    })
})

router.post('/password', async (req, res) => {

    if (!req.user) {
        res.redirect('/login');
        return;
    }

    const match = await bcrypt.compare(req.body.password, req.user.password);
    if (!match) {
        res.send({
            msg: 'Current password incorrect!'
        });
        return;
    }

    const password = await bcrypt.hash(req.body.newpass, saltRounds);
    const rs = await mLoad.all(`update user set password='${password}' where id='${req.user.id}'`);

    if (!rs) {
        res.send({
            msg: 'Change password failed! Try again.'
        });
        return;
    }

    res.send({
        msg: 'Change password success!',
        k: 1
    });
})

router.post('/edit', async (req, res) => {

    if (!req.user) {
        res.redirect('/login');
        return;
    }

    let verified = req.user.verified;
    if (req.body.email != req.user.email)
        verified = 0;

    const rs = await mLoad.all(`update user set email='${req.body.email}', first='${req.body.first}', last='${req.body.last}' where id='${req.user.id}'`);

    if (!rs) {
        res.send({
            msg: 'Change profile failed! Try again.'
        });
        return;
    }

    if (verified)
        res.send({
            msg: 'Change profile success!'
        });
    else
        res.send({
            msg: 'Change profile success!',
            id: req.user.id
        });
})

router.post('/review', async (req, res) => {

    if (!req.user) {
        res.redirect('/login');
        return;
    }

    const time = require('moment')().format('YYYY-MM-DD HH:mm:ss');
    const data = {
        id: parseInt(req.body.item),
        user: req.user.id,
        text: req.body.text,
        rate: parseInt(req.body.rate),
        date: time,
        toUser: parseInt(req.body.toUser)
    };

    const rs = await mAdd.all('review', data);
    if (!rs) {
        res.send('Review failed! Try again.');
        return;
    }

    res.send('Success!');
})

router.post('/upgrade', async (req, res) => {

    if (!req.user) {
        res.redirect('/login');
        return;
    }

    if (req.user.type)
        return;

    const rs = await mLoad.all(`update user set type='1' where id='${req.user.id}'`);
    if (!rs) {
        res.send('Request failed! Try again.');
        return;
    }

    res.send('Request sent!');
})

module.exports = router;