class AnggotaDPR:
    __id  = ""
    __name = ""
    __field = ""
    __electoral_district = ""
    __position = ""
    __party = ""



    def __init__(self, id = "", name = "", field = "", electoral_district = "", position = "", party = ""):
        self.__id = id
        self.__name = name
        self.__field = field
        self.__electoral_district = electoral_district
        self.__position = position
        self.__party = party

    def getId(self):
        return self.__id
    
    def getName(self):
        return self.__name
    
    def getField(self):
        return self.__field
    
    def getElectoralDistrict(self):
        return self.__electoral_district
    
    def getPosition(self):
        return self.__position
    
    def getParty(self):
        return self.__party
    
    def setId(self, id):
        self.__id = id

    def setName(self, name):
        self.__name = name

    def setField(self, field):
        self.__field = field

    def setElectoralDistrict(self, electoral_district):
        self.__electoral_district = electoral_district

    def setPosition(self, position):
        self.__position = position

    def setParty(self, party):
        self.__party = party

    

    

    