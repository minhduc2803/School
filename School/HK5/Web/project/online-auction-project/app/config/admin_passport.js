const LocalStrategy = require('passport-local').Strategy;
const bcrypt = require('bcryptjs');
const mUser = require('../models/admin_login');

module.exports = (admin_passport) => {

    admin_passport.serializeUser((user, done) => {

        done(null, user.id);
    });

    admin_passport.deserializeUser(async (id, done) => {
        const user = await mUser.byId(id);
        done(null, user);
    });

    admin_passport.use('local-login', new LocalStrategy({
            passReqToCallback: true
        },

        async (req, username, password, done) => {

            const user = await mUser.byUser(username);

            if (!user)
                return done(null, false, req.flash('message', 'Wrong username!'));

            const match = await bcrypt.compare(password, user.password);

            if (!match)
                return done(null, false, req.flash('message', 'Wrong password!'));

            return done(null, user);
        }));
}
