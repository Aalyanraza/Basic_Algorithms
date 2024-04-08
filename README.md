# Data Structure Assignments

Welcome to the Data Structure Assignments repository! This repository contains solutions to various assignments related to basic algorithms and testing in data structures.

## Contents

1. [ArrayBasics](#arraybasics)
2. [WarehouseAlgorithm](#warehousealgorithm)
3. [MaximizeProfit](#maximizeprofit)
4. [MergeBookingSchedules](#mergebookingschedules)
5. [MakeBookingSchedules](#makebookingschedules)

## ArrayBasics

The `ArrayBasics` class provides essential operations over one-dimensional and two-dimensional arrays. It includes methods for finding the maximum and minimum values, swapping elements, shifting arrays, creating random arrays, and more.

### Methods

- `findMax`: Finds the maximum value occurring in the array between specified positions.
- `findMaxPos`: Returns the position of the maximum value in the array between specified positions.
- `findMin`: Finds the minimum value occurring in the array between specified positions.
- `findMinPos`: Returns the position of the minimum value in the array between specified positions.
- `swap`: Swaps the elements at specified positions in the array.
- `shiftRight`: Shifts elements to the right in the array from a specified start to end position.
- `shiftLeft`: Shifts elements to the left in the array from a specified start to end position.
- `createRandomArray`: Creates and returns a random array with specified size and element range.
- `createRandomMatrix`: Creates and returns a random two-dimensional array with specified rows, columns, and element range.
- `copyArray`: Creates and returns a copy of the array.
- `copyMatrix`: Creates and returns a copy of the two-dimensional array.
- `findInArray`: Returns the position of a specific value in the array.
- `findInSortedArray`: Returns the position of a specific value in a sorted array (binary search).
- `findFirstInSortedArray`: Returns the first position where a specific value occurs in a sorted array.

## WarehouseAlgorithm

The `WarehouseAlgorithm` class contains algorithms related to warehouse management. It includes methods for determining whether there is a close pair of boxes fulfilling an order and maximizing profit from selling oil barrels.

### Methods

- `hasClosePair`: Determines if there is a close pair of boxes fulfilling a specific order.

## MaximizeProfit

The `maximizeProfit` function optimizes profit for selling oil barrels to potential buyers. It takes into account the number of barrels available, buyer orders, prices, and storage costs.

### Parameters

- `m`: Total number of oil barrels available.
- `n`: Number of potential buyers.
- `a[]`: Array containing the number of barrels each potential buyer wants.
- `p[]`: Array containing the prices offered by each potential buyer.
- `s`: Storage cost per unsold barrel.

### Return Value

- Returns the maximum profit achievable.

## MergeBookingSchedules

The `mergeBookingSchedules` function merges booking schedules for room reservations, ensuring that all talk requests are accommodated efficiently.

## MakeBookingSchedules

The `makeBookingSchedules` function creates booking schedules based on room availability and talk requests.
