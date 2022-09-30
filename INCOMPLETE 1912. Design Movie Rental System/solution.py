import copy 


class MovieRentingSystem:
    #SHOPS = [ITEM1, ITEM2...]
    #ITEM = [SHOP_ID, MOVIE, PRICE]
    shops = []
    rentedMovies = []
    def __init__(self, n: int, entries: list[list[int]]):
        self.shops = [[] for _ in range(n)]
        for entry in entries:
            self.shops[entry[0]].append(entry)

    def search(self, movie: int) -> list[int]:
        foundMovies = []
        for shop in self.shops:
            for movies in shop:
                if movies[1] == movie:
                    foundMovies.append(movies)
                    break
        foundMovies = sorted(foundMovies, key = lambda x: (x[2], x[0])).copy()
        for i in range(len(foundMovies)):
            foundMovies[i] = foundMovies[i][0]
        if len(foundMovies) > 5:
            return foundMovies[:5]
        return foundMovies
    def rent(self, shop: int, movie: int) -> None:
        for i in self.shops:
            if len(i) == 0 or i[0][0] != shop:
                continue
            for x in i:
                if x[1] == movie:
                    self.rentedMovies.append(x)
                    return 

    def drop(self, shop: int, movie: int) -> None:
        for i in self.shops:
            if len(i) == 0 or i[0][0] != shop:
                continue
            for x in i:
                if x[1] == movie:
                    self.rentedMovies.remove(x)
                    return 

    def report(self) -> list[list[int]]:
        report = copy.deepcopy(sorted(self.rentedMovies, key = lambda x: (x[2], x[0], x[1])))
        for i in report:
            del i[2]
        if len(report) > 5:
            return report[:5]
        return report



#Your MovieRentingSystem object will be instantiated and called as such:
obj = MovieRentingSystem(10, [[0,418,3],[9,5144,46],[2,8986,29],[6,1446,28],[3,8215,97],[7,9105,34],[6,9105,30],[5,1722,94],[9,528,40],[3,850,77],[3,7069,40],[8,1997,42],[0,8215,28],[7,4050,80],[4,7100,97],[4,9686,32],[4,2566,93],[2,8320,12],[2,5495,56]])
print(obj.search(7837))
print(obj.search(5495))
print(obj.rent(4,7100))
print(obj.search(9105))
print(obj.search(1446))
print(obj.report())
print(obj.search(9869))
print(obj.drop(4,7100))
