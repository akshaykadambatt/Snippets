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
#### Other $loop stuff
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
```

### Requests 
#### Retrieving Boolean Input Values
```php
//returns true for 1, "1", true, "true", "on", and "yes". All other values will return false:
$archived = $request->boolean('archived'); 
```

### File storage
```php
Route::post('process', function (Request $request) {
    $path = $request->file('photo')->store('photos'); //Or $request->photo->store('images')
    dd($path); // photos/3hcX8yrOs2NYhpadt4Eacq4TFtpVYUCw6VTRJhfn.png

    $photo = $request->file('photo');
    $filename = 'profile-photo-' . $request->id . '.' . $file->getClientOriginalExtension(); //Or $request->photo->extension()
    $path = $photo->storeAs('photos', $filename);
    dd($path); // photos/profile-photo-100.png

    //Or Multiple files
    // $paths  = [];
    // foreach ($photos as $photo) {
    //     $extension = $photo->getClientOriginalExtension();
    //     $filename  = 'profile-photo-' . time() . '.' . $extension;
    //     $paths[]   = $photo->storeAs('photos', $filename);
    // }
    //
    // dd($paths); //array:2 ["photos/profile-photo-1517315875.gif","photos/profile-photo-1517315875.png"]
});
```

#### Retriving files
```php
$filename = User::where('id', Auth::user()->id())->firstOrFail('filename');
$filename = 'profile-photo-' . Auth::user()->id() . '.jpg';
$path = Storage::path('photos/' . $filename);

if(Storage::exists($path)){
        return Response::download($path, $filename);
}
```

### Eloquent
```php
//Set the entry, i.e. update existing entry OR create then update that entry
public function setDashboardConfigs($vars)
{ 
    $entry = DashboardSetting::firstOrNew(
        ['role_id' => $vars['id']] //Retrive if role_id=num exist or instantiate a new DashboardSetting instance
    );
    $entry->dashboard_items = json_encode($vars['items']);
    $entry->save();
    return response()->json($entry->toArray());
}
```