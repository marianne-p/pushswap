# push_swap

Push_swap is about developing an algorithm which would sort the stacks in the lowest number of operations. There is a limited number of operations available, and the programme has to determine when to rotate both or just one stack etc.

<img width="647" height="697" alt="image" src="https://github.com/user-attachments/assets/6551be31-1dba-4fed-985d-837c05e772c3" />

## About the algorithm used

It's the so-called **"Turk" algorithm**. Each turn it works out how many moves every element would need to reach its correct place in the other stack, then moves the cheapest one.

### Step 0: Replace values with ranks

`push_swap` copies the input, quick-sorts the copy, and gives every node an index `i` equal to its position in the sorted order (`create_linkli.c`). So `-500, 42, 7` become ranks `0, 2, 1`. After that the algorithm compares ranks, not the actual values.

### Small inputs (fewer than 6 numbers): `sort_small_stack.c`

- **2:** one `sa` if needed.
- **3:** `sort_three_a`. If the largest is on top, `ra`; if it's in the middle, `rra`; then `sa` if the top two are out of order. That's always 2 moves or fewer.
- **4 / 5:** push 1 or 2 numbers to B, sort the remaining 3, insert the pushed ones back with the B→A routine, then rotate the smallest to the top.

### Large inputs: `sort_stack` in `sort_stack_v2.c`

1. **Seed B.** Push the first 3 numbers to B and sort them in *descending* order (`sort_three_b`).
2. **Move A to B by cheapest cost** (`from_a_to_b`), repeating until only 3 numbers are left in A:
   - **Rotation cost** (`count_cost`): an element in the top half of a stack costs its distance from the top (`ra`/`rb`). One in the bottom half costs its distance from the bottom (`rra`/`rrb`). The `above` flag records which half it's in.
   - **Target** (`find_smaller_target_in_b`): for each element of A, the target is the closest *smaller* number in B. It has to sit directly under that number so B stays descending. If nothing in B is smaller, the target is B's maximum.
   - **Pick** (`pick_cheapest`): total cost = cost to bring the element to the top of A + cost to bring its target to the top of B. The lowest total wins.
   - **Execute** (`move_to_b`): if both moves go the same direction, it uses combined `rr` / `rrr` to rotate both stacks at once. That's the main saving. Then it finishes whichever stack still needs rotating and does `pb`. If the directions differ, it rotates each stack separately (`rotate_separately`).
3. **Sort the last 3 in A** with `sort_three_a`.
4. **Move B back to A by cheapest cost** (`from_b_to_a`). This mirrors step 2: each element of B targets the closest *larger* number in A, falling back to A's minimum. It picks the cheapest, rotates (using `rr`/`rrr` when possible), and does `pa`. Each element lands directly above its successor, so A stays sorted, just possibly rotated.
5. **Final rotation** (`rotate_a_in_order`): rotate the smallest element to the top, choosing `ra` or `rra` by whichever is shorter.

In short, B acts as a descending holding stack. Every push is chosen by cost, so the numbers come back into A already in order and only one last rotation is needed.

## My result

<img width="888" height="222" alt="image" src="https://github.com/user-attachments/assets/78f57e20-e68d-4233-bb37-29a59c0f68a8" />


