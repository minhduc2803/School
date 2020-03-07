const express = require('express');
const router = express.Router();
const nodemailer = require('nodemailer');

const mUser = require('../models/user');
const mLoad = require('../models/load');

router.post('/', async (req, res) => {

    const id = parseInt(req.body.id);
    const user = await mUser.byId(id);
    if (!user || user.verified) return;

    const otp = Math.floor(1000 + Math.random() * 9999);
    const rs = await mLoad.all(`update user set otp='${otp}' where id='${id}'`);
    if (rs) {

        var transporter = nodemailer.createTransport({
            host: 'smtp.gmail.com',
            port: 587,
            secure: false,
            requireTLS: true,
            auth: {
                user: 'online.auction.project.dddd@gmail.com',
                pass: 'Matma123'
            }
        });

        var mailOptions = {
            from: 'online.auction.project.dddd@gmail.com',
            to: `${user.email}`,
            subject: 'Verification code',
            text: `${otp}`
        };

        console.log(mailOptions);

        transporter.sendMail(mailOptions, (error, info) => {
            if (error) {
                console.log(error);
            } else {
                console.log('Email sent: ' + info.response);
                res.send('Check code in your email!');
            }
        });
    }
});

module.exports = router;