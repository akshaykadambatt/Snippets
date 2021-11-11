### Loop variables in blade
Check if the item is first or last in the collection.
```php
@foreach ($users as $user)
    @if ($loop->first)
        This is the first iteration.
    @endif

    @if ($loop->last)
        This is the last iteration.
    @endif

    <p>This is user {{ $user->id }}</p>
@endforeach
```

| Property      | Description |
| ----------- | ----------- |
| $loop->index      | The index of the current loop iteration (starts at 0).       |
| $loop->iteration   | The current loop iteration (starts at 1).        |
| $loop->remaining   | The iterations remaining in the loop.        |
| $loop->count   | The total number of items in the array being iterated.        |
| $loop->first   | Whether this is the first iteration through the loop.        |
| $loop->last   | Whether this is the last iteration through the loop.        |
| $loop->even   | Whether this is an even iteration through the loop.        |
| $loop->odd   | Whether this is an odd iteration through the loop.        |
| $loop->depth   | The nesting level of the current loop.        |
| $loop->parent   | When in a nested loop, the parent's loop variable.        |

### Comments
```php
{{-- This comment will not be present in the rendered HTML --}}
```php