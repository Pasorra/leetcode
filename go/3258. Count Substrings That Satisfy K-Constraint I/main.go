package main

import "fmt"

func countKConstraintSubstrings(s string, k int) int {
	res := 0
	start := 0
	end := 0
	n := len(s)
	for start < n {
		ones := 0
		zeros := 0
		end = start
		for end < n {
			if s[end] == '0' {
				zeros++
			} else {
				ones++
			}
			if zeros > k && ones > k {
				break
			}
			end++
			res++
		}
		start++
	}
	return res
}

func main() {
	fmt.Println(countKConstraintSubstrings("11111", 1))
}
