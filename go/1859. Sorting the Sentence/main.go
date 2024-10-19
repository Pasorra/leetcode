package main

import (
	"strconv"
	"strings"
)

func sortSentence(s string) string {
	split := strings.Split(s, " ")
	arr := make([]string, len(split))
	for _, sentence := range split {
		index := -1
		for i := len(sentence) - 1; i >= 0; i-- {
			v := sentence[i] - '0'
			if v <= 9 {
				index = i
			} else {
				break
			}
		}
		place, _ := strconv.Atoi(sentence[index:])
		arr[place-1] = sentence[:index]
	}
	return strings.Join(arr, " ")
}

func main() {
	println(sortSentence("is2 sentence4 This1 a3"))
}
