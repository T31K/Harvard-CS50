function blink()
{
    let blinkObject = document.querySelector('td');
    if (blinkObject.style.visbility === 'hidden')
    {
        blinkObject.style.visbility == 'visible';
    }
    else
    {
        blinkObject.style.visbility === 'hidden';
    }
}

window.setInterval(blink,500)
