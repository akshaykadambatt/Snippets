[laravel](Laravel.md)  

### Average of array
```php
$rating = array_filter($rating); //remove empty vals
if(count($rating)) { //check if empty
  $avgRating = array_sum($rating)/count($rating); // sum/count
}
```

### Remove keys from associative array
```php
$array = [
    0 => 44,
    2 => 34,
    12 => 14,
    3 => 974,
];
$array = array_values($array);
//Now $array = [44,34,14,974];
```
