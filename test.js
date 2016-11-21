var getHeapSpaceStatistics = require('./');

//console.log(getHeapSpaceStatistics());
var assert = require('assert');
describe('v8-heap-space-statistics', function() {

	it('should return not empty array', function() {
		var stats = getHeapSpaceStatistics();
		assert.ok(Array.isArray(stats), 'Returned value is not an array');
		assert.ok(stats.length > 0, 'Returned array is empty');
	});

	it('should return array of objects with required list of properties', function() {
		getHeapSpaceStatistics().forEach(function (space) {
			assert.ok(!!space, 'Stats object is empty');
			assert.ok(
				'space_name' in space &&
				'space_size' in space &&
				'space_used_size' in space &&
				'space_available_size' in space &&
				'physical_space_size' in space,
				'Space object does not contain all required properties'
			);
		});
	});
});