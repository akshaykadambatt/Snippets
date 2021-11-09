## Select items

```js
// with jQuery
// Hide all instances of .box
$(".box").hide();// Without jQuery
// Iterate over the nodelist of elements to hide all instances of .box
document.querySelectorAll(".box").forEach(box => { box.style.display = "none" })
```
