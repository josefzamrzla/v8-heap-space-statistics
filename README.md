# getHeapSpaceStatistics

Heap space usage statistics for Node.js version 4.

Like ```require('v8').getHeapSpaceStatistics()``` in newer versions of Node - it returns statistics about the V8 heap spaces, i.e. the segments which make up the V8 heap.
                                              
The value returned is an array of objects containing the following properties:

* __space_name__: string
* __space_size__: number
* __space_used_size__: number
* __space_available_size__: number
* __physical_space_size__: number


__More info__: https://nodejs.org/api/v8.html#v8_v8_getheapspacestatistics


### Install
```bash
npm install v8-heap-space-statistics
```

### Sample usage
```javascript
var getHeapSpaceStatistics = require('v8-heap-space-statistics');
console.log(getHeapSpaceStatistics());
```


### Sample output

```javascript
[
  {
    space_name: 'new_space',
    space_size: 4127744,
    space_used_size: 741496,
    space_available_size: 1322376,
    physical_space_size: 4127744
  },
  {
    space_name: 'old_space',
    space_size: 3095808,
    space_used_size: 2208792,
    space_available_size: 7352,
    physical_space_size: 3095808
  },
  {
    space_name: 'code_space',
    space_size: 1019904,
    space_used_size: 848864,
    space_available_size: 0,
    physical_space_size: 1019904
  },
  {
    space_name: 'map_space',
    space_size: 1031936,
    space_used_size: 224752,
    space_available_size: 0,
    physical_space_size: 1031936
  },
  {
    space_name: 'large_object_space',
    space_size: 0,
    space_used_size: 0,
    space_available_size: 1492107008,
    physical_space_size: 0
  } 
]
```