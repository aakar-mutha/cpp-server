function checkAddress(checkbox)
{
    if (checkbox.checked)
    {
      $(".showcase").hide();
      $(".experience").hide();
      $(".education").hide();
      $(".skills").hide();
      $(".interests").hide();
      $(".awards").hide();

    }
    else
    {
      $(".showcase").show();
      $(".experience").show();
      $(".education").show();
      $(".skills").show();
      $(".interests").show();
      $(".awards").show();
    }
}
var c = document.querySelector(".toggler");
function gosec(sec)
{
  var elem = document.querySelector("." + sec);
  c.checked = false;
  checkAddress(c);
  elem.scrollIntoView({behavior: "smooth"})
}

function resume(){
  c.checked = false;
  checkAddress(c);
}