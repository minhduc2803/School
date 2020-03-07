const express = require('express');
const router = express.Router();

const mAdd = require('../models/add');
const mLoad = require('../models/load');

router.post('/', async (req, res) => {

    if (!req.user)
        return;

    if (!req.user.verified) {

        res.send({
            msg: 'Account not verified!',
            id: req.user.id
        });
        return;
    }

    const item = parseInt(req.body.id);
    const bid = parseInt(req.body.bid);
    const allow = (req.user.rate < 80) ? 0 : 1;
    const time = require('moment')().format('YYYY-MM-DD HH:mm:ss');
    const data = {
        id: item,
        user: req.user.id,
        cost: bid,
        allow: allow,
        create: time
    }

    const ck = await mLoad.all(`select * from bid where id='${item}' and user='${req.user.id}'`);

    if (!ck || !ck[0]) {
        await mAdd.all('bid', data);
        res.send({
            msg: 'Placed!'
        });
        return;
    }

    if (ck[0].cost >= bid) {
        res.send({
            msg: 'Place higher!'
        });
        return;
    }

    await mLoad.all(`update bid set cost='${bid}', create='${time}' where id='${item}' and user='${req.user.id}'`);
    res.send({
        msg: 'Placed!'
    });
});

module.exports = router;