[laravel](Laravel.md)  

### Average of array
```php
$rating = array_filter($rating); //remove empty vals
if(count($rating)) { //check if empty
  $avgRating = array_sum($rating)/count($rating); // sum/count
}
```
