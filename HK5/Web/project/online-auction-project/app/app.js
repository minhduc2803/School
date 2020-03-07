const express = require('express');
const exphbs = require('express-handlebars');
const bodyParser = require('body-parser');
const cookieParser = require('cookie-parser');
const session = require('express-session');
const flash = require('connect-flash');

var createError = require('http-errors');
var passport = require('passport');


var Passport = require('passport').Passport,
    passport = new Passport(),
    admin_passport = new Passport();
    require('./config/passport')(passport);
    require('./config/admin_passport')(admin_passport);
const app = express();
const port = 3000;

const hbs = exphbs.create({
    defaultLayout: 'main',
    extname: 'hbs',
    helpers: {
        equal: function (a, b, options) {

            return (a == b) ? options.fn(this) : options.inverse(this);
        },
        time: (date, format) => {

            const moment = require('moment');
            return moment(date).format(format);
        },
        partial: (name) => {
            return name;
        }
    },
    partialsDir  : [

        __dirname + '/views/partials',
    ]
})

app.engine('hbs', hbs.engine);

app.set('view engine', 'hbs');

app.use(express.static(__dirname + '/public'));
app.use(bodyParser.urlencoded({
    extended: true
}));
app.use(bodyParser.json());
app.use(cookieParser());
app.use(session({
    secret: 'qwerty',
    resave: true,
    saveUninitialized: false,
    cookie: {
        expires: 600000
    }
}));
app.use(passport.initialize());
app.use(passport.session());
app.use(flash());
app.use(admin_passport.initialize());
app.use(admin_passport.session());
app.use(flash());

app.use('/', require('./routers/home'));
app.use('/cat', require('./routers/list'));
app.use('/pro', require('./routers/item'));
app.use('/search', require('./routers/search'));
app.use('/register', require('./routers/register'));
app.use('/verify', require('./routers/verify'));
app.use('/login', require('./routers/login')(passport));
app.use('/wl', require('./routers/wl'));
app.use('/bid', require('./routers/bid'));
app.use('/otp', require('./routers/otp'));
app.use('/acc/', require('./routers/acc'));

app.use('/admin/', require('./routers/admin')(admin_passport));

app.use(function (req, res, next) {

    next(createError(404));
});
app.use(function (err, req, res, next) {

    res.status(err.status || 500);
    res.render('home', {
        layout: 'main',
        contain: 'error',
        message: err.message,
        status: err.status
    });
});

app.listen(port, () => console.log(`http://localhost:${port} is running!`));