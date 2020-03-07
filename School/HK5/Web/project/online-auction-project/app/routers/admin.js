const express = require('express');
const router = express.Router();

const User = require('../models/admin');
const Product = require('../models/admin');

module.exports = (admin_passport) => {
router.post('/login', admin_passport.authenticate('local-login', {

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
    return res.redirect('/login');
});


router.get('/', (req, res) => {
    if(!req.isAuthenticated()) return res.redirect('/login');
    res.redirect('/admin/user/bidder');
});
router.get('/user', (req, res) => {
    if(!req.isAuthenticated()) return res.redirect('/login');
    res.redirect('/admin/user/bidder');
});
router.get('/user/:tag', async (req,res) => {
    if(!req.isAuthenticated()) return res.redirect('/login');
    const tag = req.params.tag;
    let id_tag = 0;
    let table = 'user';
    switch(tag) {
        case 'seller':  id_tag = 2; break; 
        case 'browsinglist': id_tag = 1;break;
        case 'admin': {
            id_tag = 3;
            table = 'admin';
        }
    }
    const user = await User.user(id_tag, table);
    res.render('home', {
        css: ['style'],
        js: ['/javascripts/admin.js'],
        layout: 'ad',
        contain: 'admin/admin',
        title: 'Admin',
        nav: 'admin/header/user',
        content: 'admin/content/'+tag,
        user: user,
        active_nav: [tag],
        admin_name: req.user.username
    });
   
});

router.get('/product', async (req, res) => {
    if(!req.isAuthenticated()) return res.redirect('/login');
    const firstrow = await Product.first();
    res.redirect('/admin/product/'+firstrow[0].cat+'/'+firstrow[0].sub);
});
router.get('/product/:cat', async (req, res) => {
    if(!req.isAuthenticated()) return res.redirect('/login');
    const cat = req.params.cat;
    const subcat = await Product.subcat(cat);
    res.redirect('/admin/product/'+cat+'/'+subcat[0].sub);
});
router.get('/product/:cat/:sub', async (req,res) => {
    if(!req.isAuthenticated()) return res.redirect('/login');
    const cat = req.params.cat;
    const sub = req.params.sub;
    const category = await Product.category();
    const subcat = await Product.subcat(cat);
    const products = await Product.products(sub);

    res.render('home', {
        css: ['style'],
        js: ['/javascripts/script.js'],
        layout: 'ad',
        contain: 'admin/admin',
        title: 'Admin',
        nav: 'admin/header/product',
        content: 'admin/content/product',
        product_link: 'admin/content/product/items',
        active_cat: [cat],
        active_sub: [sub],
        category: category,
        subcat: subcat,
        products: products,
        admin_name: req.user.username
    });
});
router.get('/product/:cat/:sub/:id', async (req,res) => {
    if(!req.isAuthenticated()) return res.redirect('/login');
    const cat = req.params.cat;
    const sub = req.params.sub;
    const id = req.params.id;
    const category = await Product.category();
    const subcat = await Product.subcat(cat);
    const product = await Product.product(id);

    res.render('home', {
        css: ['style'],
        js: ['/javascripts/script.js'],
        layout: 'ad',
        contain: 'admin/admin',
        title: 'Admin',
        nav: 'admin/header/product',
        content: 'admin/content/product',
        product_link: 'admin/content/product/item',
        active_cat: [cat],
        active_sub: [sub],
        category: category,
        subcat: subcat,
        item: product[0],
        admin_name: req.user.username
    });
});
router.post('/user/mote', async(req, res) => {
    const id = req.body.id;
    const type = req.body.type;
    const result = await User.mote(id,type);
    console.log(result);
    if(type == 1) res.redirect('/admin/user/browsinglist');
    else res.redirect('/admin/user/seller');
});
router.post('/product/addc', async(req, res) => {
    const name = req.body.name;
    const result = await Product.addcat(name);

    console.log(result);
    res.redirect('/admin/product/'+name);
});
router.post('/product/adds', async(req, res) => {
    const sub = req.body.sub;
    const cat = req.body.cat;
    const result = await Product.addsub(sub,cat);

    console.log(result);
    res.redirect('/admin/product/'+cat+'/'+sub);
});

return router;
}
