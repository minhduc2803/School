const express = require('express');
const fs=require('fs');
const router = express.Router();

const mCat = require('../models/category');

router.get('/upload', async (req, res) => {

    if (!req.user) {
        res.redirect('/login');
        return;
    }

    if (req.user.type != 2) {
        res.redirect('/');
        return;
    }

    const cats = await mCat.cat();
    const subs = await mCat.all();

    res.render('home', {
        css: ['style'],
        js: ['/javascripts/script.js'],
        contain: 'seller/upload',
        title: 'Upload',
        cats: cats,
        subs: subs,
        user: req.user
    });
})

router.post('/upload/validation',async(req,res) =>
{
    const request=req;
    //console.log(request);
    var path = `../app/public/images/sp/${req.user.id}`;
    fs.mkdir(path,function (err) {
        if (err) {
            console.log('failed to create directory', err);
        } 
    });
})
module.exports = router;
