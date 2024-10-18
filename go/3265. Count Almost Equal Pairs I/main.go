package main

func check(num1 int, num2 int) int {
	discrepancy := 0
	nums1 := make([]int, 10)
	nums2 := make([]int, 10)
	for num1 != 0 || num2 != 0 {
		n1 := num1 % 10
		n2 := num2 % 10
		nums1[n1]++
		nums2[n2]++
		if n1 != n2 {
			discrepancy++
		}
		num1 /= 10
		num2 /= 10
	}
	if discrepancy > 2 {
		return 0
	}
	for i := 0; i <= 10; i++ {
		if nums1[i] != nums2[i] {
			return 0
		}
	}
	return 1
}

func countPairs(nums []int) int {
	result := 0
	for i := 0; i < len(nums); i++ {
		for j := i; j < len(nums); j++ {
			result += check(nums[i], nums[j])
		}
	}
	return result
}

func main() {
	result := countPairs([]int{3, 12, 30, 17, 21})
	println(result)
}
