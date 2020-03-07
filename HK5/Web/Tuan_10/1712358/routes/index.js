var express = require('express');
var mCat = require('../models/categories');
var mPro = require('../models/products');
var router = express.Router();

/* GET home page. */
router.get('/', async function(req, res, next) {
  
  const cats = await mCat.all();
  const id = parseInt(cats[0].CatID);
  const pros = await mPro.allByCatId(id);
  
  res.render('index', {cat:cats, pro:pros, id:id});
});
router.get('/:id/products', async function(req, res, next) {
  
  const cats = await mCat.all();
  const id = parseInt(req.params.id);
  const pros = await mPro.allByCatId(id);
 
  res.render('index', {cat:cats, pro:pros, id:id});
});
router.get('/:idc/:idp/detail', async function(req, res, next) {
  const cats = await mCat.all();
  
  const idc = parseInt(req.params.idc);
  const idp = parseInt(req.params.idp);
  console.log(idc,idp);
  const product = await mPro.ById(idp);

  res.render('detail', {cat:cats, id:idc, detail:product});

});
module.exports = router;
