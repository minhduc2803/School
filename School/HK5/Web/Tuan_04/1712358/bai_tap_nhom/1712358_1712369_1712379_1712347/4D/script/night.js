function check() {
    var top = document.getElementById("top");
    var bg = document.getElementById("bg");
    var title = document.getElementById("title");
    var home = document.getElementById("home");
    var night = document.getElementById("night");
    var dl = document.getElementById("dl");
    var info = document.getElementById("info");
    var line = document.getElementById("line");
    var link = document.getElementById("link");
    var bot = document.getElementById("bot");
    

    const theme = localStorage.getItem('theme');
    
    if (theme === 'light')
    {
        top.className = "fixed light";
        bg.className = "light";     
        title.className = "light"; 
        home.className = "light";
        night.className = "light";
        dl.src = "../../image/moon.png";
        info.className = "light";
        line.className = "light";
        link.className = "light";
        bot.className = "light";

        localStorage.setItem('theme', 'light');
    }
    else {
        top.className = "fixed dark";
        bg.className = "dark";    
        title.className = "dark";  
        home.className = "dark";
        night.className = "dark";
        dl.src = "../../image/sun.png";
        info.className = "dark";
        line.className = "dark";
        link.className = "dark";
        bot.className = "dark";

        localStorage.setItem('theme', 'dark');
    }
}

function night() {
    var top = document.getElementById("top");
    var bg = document.getElementById("bg");
    var title = document.getElementById("title");
    var home = document.getElementById("home");
    var night = document.getElementById("night");
    var dl = document.getElementById("dl");
    var info = document.getElementById("info");
    var line = document.getElementById("line");
    var link = document.getElementById("link");
    var bot = document.getElementById("bot");
    
    const theme = localStorage.getItem('theme');

    if (theme === 'light') {
        top.className = "fixed dark";
        bg.className = "dark";   
        title.className = "dark";   
        home.className = "dark";
        night.className = "dark";
        dl.src = "../../image/sun.png";
        info.className = "dark";
        line.className = "dark";
        link.className = "dark";
        bot.className = "dark";

        localStorage.setItem('theme', 'dark');
    }
    else {
        top.className = "fixed light";
        bg.className = "light";   
        title.className = "light";   
        home.className = "light";
        night.className = "light";
        dl.src = "../../image/moon.png";
        info.className = "light";
        line.className = "light";
        link.className = "light";
        bot.className = "light";

        localStorage.setItem('theme', 'light');
    }
}