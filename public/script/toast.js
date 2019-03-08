function afficherToast(message){
    var element = $("#toast");
    element.children().remove();
    element.append("<p>"+message+"</p>");
    element.attr("class","show");
    setTimeout(function(){
	element.attr("class"," ");
    },3000);
}
