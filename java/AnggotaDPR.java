public class AnggotaDPR {
    private String id;
    private String name;
    private String field;
    private String electoralDistrict;
    private String position;
    private String party;

    public AnggotaDPR(){
        this.id = "";
        this.name = "";
        this.field = "";
        this.electoralDistrict = "";
        this.position = "";
        this.party = "";
    }

    public AnggotaDPR(String id, String name, String field, String electoralDistrict, String position, String party) {
        this.id = id;
        this.name = name;
        this.field = field;
        this.electoralDistrict = electoralDistrict;
        this.position = position;
        this.party = party;

    }

    public String getId() {
        return this.id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public String getName() {
        return this.name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getField() {
        return this.field;
    }

    public void setField(String field) {
        this.field = field;
    }

    public String getElectoralDistrict() {
        return this.electoralDistrict;
    }

    public void setElectoralDistrict(String electoralDistrict) {
        this.electoralDistrict = electoralDistrict;
    }

    public String getPosition() {
        return this.position;
    }

    public void setPosition(String position) {
        this.position = position;
    }

    public String getParty() {
        return this.party;
    }

    public void setParty(String party) {
        this.party = party;
    }

    
}