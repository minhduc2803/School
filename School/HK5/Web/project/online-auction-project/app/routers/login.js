const express = require('express');
const router = express.Router();

const mCat = require('../models/category');

module.exports = (passport) => {

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
            contain: 'auth/login',
            title: 'Login',
            cats: cats,
            subs: subs,
            message: req.flash('message')
        });
    });

    router.post('/', passport.authenticate('local-login', {

        failureRedirect: '/login',
        failureFlash: true
    }), (req, res) => {

        if (req.body.remember) {
            req.session.cookie.maxAge = 1000 * 60 * 3;
        } else {
            req.session.cookie.expires = false;
        }
        res.redirect('/')
    });

    router.post('/admin', passport.authenticate('local-login', {

        failureRedirect: '/login',
        failureFlash: true
    }), (req, res) => {

        if (req.body.remember) {
            req.session.cookie.maxAge = 1000 * 60 * 3;
        } else {
            req.session.cookie.expires = false;
        }
        res.redirect('/admin')
    });

    router.get('/logout', (req, res) => {

        req.logout();
        res.redirect('/');
    });

    return router;
}