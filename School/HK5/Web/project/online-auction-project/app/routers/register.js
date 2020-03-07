const express = require('express');
const router = express.Router();
const bcrypt = require('bcryptjs');
const saltRounds = 10;

const mCat = require('../models/category');
const mUser = require('../models/user');
const mAdd = require('../models/add');

router.get('/', async (req, res) => {

    if (req.user) {
        res.redirect('/');
        return;
    }

    const cats = await mCat.cat();
    const subs = await mCat.all();

    res.render('home', {
        css: ['style'],
        js: ['/javascripts/script.js', 'https://www.google.com/recaptcha/api.js'],
        contain: 'auth/register',
        title: 'Register',
        cats: cats,
        subs: subs,
        user: req.query.user,
        email: req.query.email,
        success: req.query.success,
        user: req.user
    });
});

router.post('/', async (req, res) => {

    let user = await mUser.byUser(req.body.username);
    if (user) {
        res.send({
            msg: 'Username exists!'
        });
        return;
    }

    user = await mUser.byEmail(req.body.email);
    if (user) {
        res.send({
            msg: 'Email exists!'
        });
        return;
    }

    const password = await bcrypt.hash(req.body.password, saltRounds);
    const time = require('moment')().format('YYYY-MM-DD HH:mm:ss');

    const data = {
        username: req.body.username,
        password: password,
        email: req.body.email,
        first: req.body.first,
        last: req.body.last,
        create: time
    };

    const rs = await mAdd.all('user', data);

    if (!rs) {
        res.send({
            msg: 'Register failed! Try agains.'
        });
        return;
    }

    console.log(rs);
    res.send({
        msg: 'Register success!',
        id: rs.insertId
    });
});

module.exports = router;