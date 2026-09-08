# Skadi — Day 3: VectorIndex & Nearest-Neighbor Search

## 1. What We Built and Why

### VectorIndex
Created a `VectorIndex` class responsible for storing and searching vectors.

A 3-dimensional index conceptually looks like:

VectorIndex
- dimension_: 3
- vectors_:
  - [1, 2, 3]
  - [5, 5, 5]
  - [9, 9, 9]

### Fixed Dimension
`VectorIndex(3)` creates an index that only accepts 3-dimensional vectors.

`dimension()` returns the configured dimension.

### Adding Vectors
Implemented `add()`.

Before storing a vector, it checks:

incoming.size() == dimension()

If dimensions don't match, Skadi throws `std::invalid_argument`.

### Index Size
Implemented `size()` to return how many vectors are currently stored.

### Nearest-Neighbor Search
Implemented `nearest(query)`.

It:

1. Validates the query dimension.
2. Rejects searching an empty index.
3. Loops through every stored vector.
4. Calculates Euclidean distance from the query.
5. Keeps track of the smallest distance.
6. Returns the closest vector.

Example:

Stored:
- [1, 2, 3]
- [5, 5, 5]
- [9, 9, 9]

Query:
- [4.9, 5.1, 5.0]

Result:
- [5, 5, 5]

This is a brute-force nearest-neighbor search.


## 2. C++ Concepts Used

### Classes and Private State
`VectorIndex` keeps its internal state private:

- `dimension_`
- `vectors_`

Users interact with the index through public methods such as:

- `dimension()`
- `size()`
- `add()`
- `nearest()`

### Constructors
The constructor establishes the index's required dimension when the object is created.

### Member Initializer Lists
Used the constructor initializer list to initialize `dimension_`.

### const References
Incoming vectors and queries are passed using const references.

This avoids an unnecessary copy while preventing the function from modifying the caller's vector.

### const Member Functions
Methods such as `dimension()`, `size()`, and `nearest()` are const because searching or inspecting the index should not modify it.

Important distinction:

const parameter -> protects the input

const after function -> protects the object

### vector of vectors
For now, vectors are stored using:

std::vector<std::vector<float>>

This is simple and works well for the first implementation.

Later we can explore more efficient contiguous storage.

### Exceptions
Invalid operations throw `std::invalid_argument`.

Examples:

- adding a vector with the wrong dimension
- searching with the wrong query dimension
- searching an empty index

### numeric_limits
Used the largest possible float as the initial "best distance".

Every real calculated distance should therefore be smaller than the starting value.


## 3. Vector Search Concepts

### Vector Index
A vector index stores vectors so they can later be searched.

### Query Vector
A query is another vector representing what we want to find similar vectors to.

### Nearest Neighbor
The nearest neighbor is the stored vector with the smallest distance from the query.

### Brute-Force Search
Our current search checks every stored vector.

For N stored vectors:

query
  |
  +--> vector 1 -> distance
  +--> vector 2 -> distance
  +--> vector 3 -> distance
  ...
  +--> vector N -> distance

Then Skadi returns the smallest.

This is simple and exact, but it becomes expensive when millions of vectors are stored.

Later we can address this with more advanced indexing techniques such as HNSW.


## Current Skadi Capabilities

Skadi can now:

- calculate dot products
- calculate Euclidean distance
- validate vector dimensions
- create a fixed-dimension vector index
- add vectors to the index
- report index size
- reject invalid vectors
- perform brute-force nearest-neighbor search
- return the closest stored vector
- verify the search with lightweight tests


## Next

Top-K search.

Instead of:

query -> nearest vector

we want:

query -> top 3 / top 5 / top K nearest vectors

This will introduce ranking multiple search results and move Skadi closer to a real vector search API.
