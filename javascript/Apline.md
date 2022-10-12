## AplineJS stuff
### Example page

```html
<html>
<head>
    <script defer src="https://unpkg.com/alpinejs@3.x.x/dist/cdn.min.js"></script>
</head>
<body>
    <div x-data="counter()" class="main">
        Step <span x-text="count"></span>   
        <div class="select-date" x-show="count==0">
            <select name="trek" id="trek-select">
                <option value="0">Zero trek</option>
                <option value="1">One trek</option>
            </select>
            <select name="date" id="date-select">
                <option value="0">Zero date</option>
                <option value="1">One date</option>
            </select>
        </div>
        <div class="manage-order" x-show="count==1">
            manage order
            <template x-for="trekker in trekkers">
                <li x-text="trekker"></li>
            </template>
            <form onsubmit="return false">
                <input name="new-trekker" id="new-trekker" x-model="newTrekker" placeholder="new-trekker"/>
                <button type='button' name="add-trekker" class="add-trekker" id="add-trekker" x-on:click="addTrekker()" >add-trekker</button>
            </form>
        </div>
        <div class="pay-order" x-show="count==2">
            pay order
            <label>
                <input type="checkbox" name="accept-terms"   /> 
                Accept Terms
            </label>
        </div>
        <button x-on:click="decrement()" x-bind:disabled="count==0">prev step</button>
        <button x-on:click="increment()" x-bind:disabled="(count==2 && terms==0)">next step</button>
    </div>
</body>
<script>
    function counter() {
      return {
        count: 0,
        terms: 0,
        trekkers: ['trekker 1', 'trekker 2', 'trkker 3'],
        newTrekker:"",
        increment() {
          this.count<2?this.count++:this.count;
        },
        decrement() {
            this.count!=0?this.count--:this.count;
        },
        addTrekker(){
            this.trekkers.push(this.newTrekker);
            this.newTrekker = "";
        }
      };
    }
    /**
     * To access these values outside of Apline's context, use;
     * 
     * const accessApline = Alpine.mergeProxies(document.querySelector('.main')._x_dataStack)
     * const count = accessApline.count //0
     * const trekkres = accessApline.trekkers // ['str', 'str', 'str']
     * 
     * OR
     * 
     * const accessApline = Alpine.evaluate(document.querySelector('.main'), '$data')
     * 
     * where document.querySelector('.main') is the host of Apline
     * */
</script>
</html>
```

#### Accessing the Apline data from outside Apline's context
To access these values outside of Apline's context, use;
```js
const accessApline = Alpine.mergeProxies(document.querySelector('.main')._x_dataStack)
//OR 
const accessApline = Alpine.evaluate(document.querySelector('.main'), '$data') // Better as per docs

const count = accessApline.count //0
const trekkres = accessApline.trekkers // ['str', 'str', 'str']
// where document.querySelector('.main') is the host of Apline
```