from AnggotaDPR import AnggotaDPR
from Table import Table

class DataController:
    __container = []

    def __init__(self):
        pass


    def getContainer(self):
        return self.__container
    
    def setContainer(self, container):
        self.__container = container

    def searchByID(self, id):
        found = False
        index = 0
        while not found and index < len(self.__container):
            if(self.__container[index].getId() == id):
                found = True
            else:
                index += 1
        
        if found:
            return self.__container[index]
        else:
            return None
        
    def createData(self):
        id = ""
        name = ""
        field = ""
        electoral_district = ""
        position = ""
        party = ""

        print("Please give attrubutes for new data:")
        print("ID                 : ", end='')
        id = input()
        print("Name               : ", end='')
        name = input()
        print("Field              : ", end='')
        field = input()
        print("Electoral District : ", end='')
        electoral_district = input()
        print("Position           : ", end='')
        position = input()
        print("Party              : ", end='')
        party = input()

        anggotaDPR = AnggotaDPR(id, name, field, electoral_district, position, party)
        
        self.__container.append(anggotaDPR)

        print("Data has been successfully created!")

    
    def modifyData(self):
        targetID = ""
        print("PLease select data to modify by ID : ", end='')
        targetID = input()
        target = self.searchByID(targetID)

        if(target is None):
            print("Data was not found!")
            return
        
        print("Data found. Please enter new data attributes")

        name = ""
        field = ""
        electoral_district = ""
        position = ""
        party = ""

        print("Please give attrubutes for new data:")
        print("Name               : ", end='')
        name = input()
        print("Field              : ", end='')
        field = input()
        print("Electoral District : ", end='')
        electoral_district = input()
        print("Position           : ", end='')
        position = input()
        print("Party              : ", end='')
        party = input()

        target.setName(name)
        target.setField(field)
        target.setElectoralDistrict(electoral_district)
        target.setPosition(position)
        target.setParty(party)

        print("Data successfully modified!")

    def deleteData(self):
        
        targetID = ""
        print("Please select data to delete by ID : ", end='')
        targetID = input()
        target = self.searchByID(targetID)

        if(target is None):
            print("Data was not found!")
            return
        
        print("Data has been found.")
        print("{}. {}".format(target.getId(), target.getName()))
        print("Confirm to delete? (y/n)")
        del_confirm = input()
        if del_confirm == 'y':
            self.__container.remove(target)
            print("Data has successfully been deleted")
        else:
            print("Cancelled data deletion")
    

    def showAll(self):
        table = Table()
        data = [["" for j in range(6)] for i in range(len(self.__container) + 1) ] # + 1 untuk diawal diisi dengan header tabel

        data[0][0] = "ID"
        data[0][1] = "Name"
        data[0][2] = "Field"
        data[0][3] = "Electoral District"
        data[0][4] = "Position"
        data[0][5] = "Party"

        for i, anggotaDPR in enumerate(self.__container):
            data[i + 1][0] = anggotaDPR.getId()
            data[i + 1][1] = anggotaDPR.getName()
            data[i + 1][2] = anggotaDPR.getField()
            data[i + 1][3] = anggotaDPR.getElectoralDistrict()
            data[i + 1][4] = anggotaDPR.getPosition()
            data[i + 1][5] = anggotaDPR.getParty()

        table.createRows(len(self.__container) + 1, 6, data)
        print("\n")
                
