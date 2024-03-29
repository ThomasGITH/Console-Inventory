# Console-Inventory
A simple inventory visually represented by ASCII characters. The '~' character represents empty space, while the other characters represent items. The items get sorted from most valuable to least valuable.

### What I've learned from this task:
I didn't actually know about the 'std::sort()' function before since I've never had need for it. I also learned to more efficiently use 'std::vector' by reserving space from the beginning for later use, rather than using 'push_back' and inefficiently resizing the array each and every time.

This task also gave me the opportunity to both test and improve my 'DynamicList' struct, which is basically just a struct that puts a layer of abstraction on top of the 'std::list' array in order to simplify its use. Honestly, there is no specific benefit to doing this rather than just using one of the standard built-in arraylists. I just wanted the learning experience.

## Output:
![inventory_screenshot](https://user-images.githubusercontent.com/31830553/68344786-2d46ff00-00f0-11ea-9c66-ff965ca409bc.png)
