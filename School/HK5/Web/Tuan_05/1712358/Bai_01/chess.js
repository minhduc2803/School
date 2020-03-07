function create_piece(name, parent_id){
    var s = document.createElement('span');
    s.className='piece';
    s.draggable='true';
    s.setAttribute('ondragstart','drag(event)');
    switch(name)
    {
        case 'd_king': s.innerHTML = '&#9818;'; s.className+=' dking'; break;
        case 'd_queen': s.innerHTML = '&#9819;'; s.className+=' dqueen'; break;
        case 'd_rook': s.innerHTML = '&#9820;'; s.className+=' drook'; break;
        case 'd_bishop': s.innerHTML = '&#9821;'; s.className+=' dbishop'; break;
        case 'd_knight': s.innerHTML = '&#9822;'; s.className+=' dknight'; break;
        case 'd_pawn': s.innerHTML = '&#9823;'; s.className+=' dpawn'; break;
        case 'l_king': s.innerHTML = '&#9812;'; s.className+=' lking'; break;
        case 'l_queen': s.innerHTML = '&#9813;'; s.className+=' lqueen'; break;
        case 'l_rook': s.innerHTML = '&#9814;'; s.className+=' lrook'; break;
        case 'l_bishop': s.innerHTML = '&#9815;'; s.className+=' lbishop'; break;
        case 'l_knight': s.innerHTML = '&#9816;'; s.className+=' lknight'; break;
        case 'l_pawn': s.innerHTML = '&#9817;'; s.className+=' lpawn'; break;
    }
    document.getElementsByClassName('empty')[parent_id].appendChild(s);
}

function load(){
    for(let i=0;i<8;i++)
    {
        for(let j=0;j<8;j++)
        {
            var d = document.createElement('div');
            d.setAttribute('ondrop','drop(event)');
            
            d.setAttribute('ondragover','allowDrop(event)');
            if(((i+j) % 2) == 0)
                d.className='empty dark';
            else
                d.className='empty light';
                
            document.getElementsByClassName('board')[0].appendChild(d);
        }
    }

    create_piece('d_knight',0);
    create_piece('d_bishop',1);
    create_piece('d_rook',2);
    create_piece('d_queen',3);
    create_piece('d_king',4);
    create_piece('d_rook',5);
    create_piece('d_bishop',6);
    create_piece('d_knight',7);
    create_piece('d_pawn',8);
    create_piece('d_pawn',9);
    create_piece('d_pawn',10);
    create_piece('d_pawn',11);
    create_piece('d_pawn',12);
    create_piece('d_pawn',13);
    create_piece('d_pawn',14);
    create_piece('d_pawn',15);

    create_piece('l_knight',48);
    create_piece('l_bishop',49);
    create_piece('l_rook',50);
    create_piece('l_queen',51);
    create_piece('l_king',52);
    create_piece('l_rook',53);
    create_piece('l_bishop',54);
    create_piece('l_knight',55);
    create_piece('l_pawn',56);
    create_piece('l_pawn',57);
    create_piece('l_pawn',58);
    create_piece('l_pawn',59);
    create_piece('l_pawn',60);
    create_piece('l_pawn',61);
    create_piece('l_pawn',62);
    create_piece('l_pawn',63);
}

function allowDrop(ev) {
    ev.preventDefault();
  }
  
  function drag(ev) {
    ev.dataTransfer.setData("text", ev.target.id);
  }
  
  function drop(ev) {
    ev.preventDefault();
    var data = ev.dataTransfer.getData("text");
    
    ev.target.appendChild(document.getElementById(data));
  }