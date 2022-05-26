# HTSeekerV2
Main Class of the library containing the methods and properties.

## Properties
| Properties | Type | Description                             |
|------------|------|-----------------------------------------|
| Address    | int  | Main Address of the Seeker. Default 0x8 |
| Mode       | int  | Current Mode of the Seeker, AC or DC    |

## Public Methods
| Method     | Type      | Description                                            |
|------------|-----------|--------------------------------------------------------|
| Initialize | void      | Function to Initialize and Construct the Seeker.       |
| Read       | IR_Result | Main function that returns the Result Values in Bytes. |

## Methods

### <mark style="background-color: #525252; color: white; padding: 5px; border-radius:5px;"> HTSeekerV2.Initialize </mark>
Use this Function to Initialize and Construct the Seeker.
```js
HTSeekerV2.Initialize( int mode );
```
### Parameters
* mode: Int between 0-1 or AC-DC.

### <mark style="background-color: #525252; color: white; padding: 5px; border-radius:5px;"> HTSeekerV2.Read </mark>
Main function that returns the Result Values in Bytes.
```js
HTSeekerV2.Read();
```

### Return Value
A Custom Structure containing the next values:
```cpp
struct IR_Result {
    byte Direction;
    byte Strength;
}
```