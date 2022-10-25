### Select items
```js
// with jQuery
// Hide all instances of .box
$(".box").hide();

// Without jQuery
// Iterate over the nodelist of elements to hide all instances of .box
document.querySelectorAll(".box").forEach(box => { box.style.display = "none" })
//OR
//Get HTMLCollection, spread it, put it in an array, give it to forEach
[...document.querySelectorAll('.box')].forEach(div=>{
    div.style.display = "none"
})
```

### Traversing the tree with parent(), next(), and prev()
```js
// with jQuery
// Return the next, previous, and parent element of .box
$(".box").next();
$(".box").prev();
$(".box").parent();

// Without jQuery
// Return the next, previous, and parent element of .box
var box = document.querySelector(".box");
box.nextElementSibling;
box.previousElementSibling;
box.parentElement;
```

### Working with events
```js
// With jQuery
$(".button").click(function(e) { /* handle */ });
$(".button").mouseenter(function(e) {  /* handle */ });
$(document).keyup(function(e) {  /* handle */  });

// Without jQuery
document.querySelector(".button").addEventListener("click", (e) => { /* handle */ });
document.querySelector(".button").addEventListener("mouseenter", (e) => { /* handle */ });
document.addEventListener("keyup", (e) => { /* handle */ });
document.querySelector(".button").onclick = function(e){ /* handle */ }
```

### Event listening for dynamically added elements
```js
// With jQuery
// Handle click events .search-result elements, 
// even when they're added to the DOM programmatically
$(".search-container").on("click", ".search-result", handleClick);

// Without jQuery
// Create and add an element to the DOM
var searchElement = document.createElement("div");
document.querySelector(".search-container").appendChild(searchElement);
// Add an event listener to the element
searchElement.addEventListener("click", handleClick);
```

### Styling elements
```js
// With jQuery
// Pass multiple styles
$(".box").css({
  "color": "#000",
  "background-color": "red"
});
// Set all styles at once (and override any existing styles)
box.style.cssText = "color: #000; background-color: red";
```

### Document ready
```js
// With jQuery
$(document).ready(function() { 
  /* Do things after DOM has fully loaded */
});

// Without jQuery
// Define a convenience method and use it
var ready = (callback) => {
  if (document.readyState != "loading") callback();
  else document.addEventListener("DOMContentLoaded", callback);
}

ready(() => { 
  /* Do things after DOM has fully loaded */ 
});
```

### Working with classes
```js
// With jQuery
// Add, remove, and the toggle the "focus" class
$(".box").addClass("focus");
$(".box").removeClass("focus");
$(".box").toggleClass("focus");

// Without jQuery
// Add, remove, and the toggle the "focus" class
var box = document.querySelector(".box");
box.classList.add("focus");
box.classList.remove("focus");
box.classList.toggle("focus");
// Add "focus" and "highlighted" classes, and then remove them
var box = document.querySelector(".box");
box.classList.add("focus", "highlighted");
box.classList.remove("focus", "highlighted");
// Remove the "focus" class and add "blurred"
document.querySelector(".box").classList.replace("focus", "blurred");
// Check if .box has a class of "focus", and do something
if (document.querySelector(".box").classList.contains("focus")) {
  // Do something...
}
```

### Array Map
```js
array = document.querySelector('#parent).children')
//array is an HTMLCollection, i.e. [Node,Node,Node,Node]
array.map(fun)
function fun(item){
    return item.dataset.id
}
//now array is [1,2,3,4]
```

### Array Map
![Array.map – map all values to an expression.](https://miro.medium.com/max/700/1*4EGwsCicbWJeml2aAm714A.gif)
![Array.filter – keep all that match a condition.](https://miro.medium.com/max/700/1*TOPYVvfMBmjajPh-fqZ9GQ.gif)
![Array.reduce – reduce all items to a single value.](https://miro.medium.com/max/700/1*dhTC_FFgiH3mKROrnDj12w.gif)

### Check if any of the parents of a node has a class/id/tag (Good when events' bubbling)
```js
function hasParentWithMatchingSelector (target:Node, selector:string) {
    const allSubMenus : NodeListOf<Element> = document.querySelectorAll(selector) 
    let myArray = Array.from(allSubMenus)
    return [...myArray].some(el =>
      el !== target && el.contains(target)
    )
  }
```

### Fetch examples
```js
//GET with params
fetch(
    '/getDashboardConfigs?' + new URLSearchParams({ //Append params to URL for GET
          val: e.currentTarget.value
    }), {
    method: "GET",
    headers: { 'Content-type': 'application/json', 'X-CSRF-TOKEN': $('meta[name="csrf-token"]').attr('content') }
  })
  .then(res => res.json())
  .then(res => {
      console.log(res);
  });

//POST fetch with body
fetch('/setDashboardConfigs', {
    method: 'POST',
    headers: { 'Content-Type': 'application/json', 'X-CSRF-TOKEN': $('meta[name="csrf-token"]').attr('content') },
    body: JSON.stringify(sendData) //OR spread new FormData(document.querySelector('#formOne'))
})
  .then(response => response.json())
  .then(data => {
      console.log(data);
  })
  .catch(() => {
      this.message = 'Failed.'
  })
```

## Date
### Date to timestamp
```js
let dataObject = new Date() //Sun Jul 10 2022 15:09:22 GMT+0530 (India Standard Time)
let timestamp = + new Date() //1657445959799
//OR
let timestamp = Number(new Date()) //1657445959799
// `+` is the Number() method operator
```

## URL
### GET params
Get all URL GET parameters as a keyed object:
```js
let getParamsObject = ([...(new URLSearchParams(window.location.search))]).reduce((prev,curr)=>(
    Object.assign(prev,{[curr[0]]:curr[1]})
  ),{})
/**
 * getParamsObject = {
 *  param: 1,
 *  param2: "new",
 * }
 * */

```