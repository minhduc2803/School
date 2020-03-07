const express = require('express');
const router = express.Router();

const mWL = require('../models/wl');

router.post('/add', async (req, res) => {
    if (req.user) {
        const user = parseInt(req.user.id);
        const item = parseInt(req.body.id);
        const rs = await mWL.addWL(user, item);

        res.send(rs);
    }
})

router.post('/rm', async (req, res) => {

    if (req.user) {
        const user = parseInt(req.user.id);
        const item = parseInt(req.body.id);
        const rs = await mWL.rmWL(user, item);

        res.send(rs);
    }
})

module.exports = router;