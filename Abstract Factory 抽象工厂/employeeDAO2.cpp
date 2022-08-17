#include <vector>

// 数据库访问相关的基类
class IDBConnection {};

class IDBConnectionFactory {
public:
    virtual IDBConnection* CreateDBConnection() = 0;
};

class IDBCommand {};

class IDBCommandFactory {
public:
    virtual IDBCommand* CreateDBCommand() = 0;
};

class IDataReader {};

class IDataReaderFactory {
public:
    virtual IDataReader* CreateDataReader() = 0;
};


// 支持sql server
class SqlConnection : public IDBConnection {

};

class SqlConnectionFactory : public IDBConnectionFactory {
public:
    virtual IDBConnection* CreateDBConnection() {
        return new SqlConnection;
    }
};

class SqlCommand : public IDBCommand {

};

class SqlCommandFactory : public IDBCommandFactory {
public:
    virtual IDBCommand* CreateDBCommand() {
        return new SqlCommand;
    }
};

class SqlDataReader : public IDataReader {

};

class SqlDataReaderFactory : public IDataReaderFactory {
public:
    virtual IDataReader* CreateDataReader() {
        return new SqlDataReader;
    }
};

// 支持oracle
class OracleConnection : public IDBConnection {

};

class OracleConnectionFactory : public IDBConnectionFactory {
public:
    virtual IDBConnection* CreateDBConnection() {
        return new OracleConnection;
    }
};

class OracleCommand : public IDBCommand {

};

class OracleCommandFactory : public IDBCommandFactory {
public:
    virtual IDBCommand* CreateDBCommand() {
        return new OracleCommand;
    }
};

class OracleDataReader : public IDataReader {

};

class OracleDataReaderFactory : public IDataReaderFactory {
public:
    virtual IDataReader* CreateDataReader() {
        return new OracleDataReader;
    }
};

class EmployeeDAO {
    IDBConnectionFactory* dbConnectionFactory;
    IDBCommandFactory* dbCommandFactory;
    IDataReaderFactory* dataReaderFactory;

public:
    std::vector<EmployeeDAO> GetEmployees() {
        IDBConnection* connection = dbConnectionFactory->CreateDBConnection();
        connection->ConnectionString("...");

        IDBCommand* command = dbCommandFactory->CreateDBCommand();
        command->CommandText("...");
        command->setConnection(connection); // 关联性

        IDataReader* reader = command->ExecuteReader(); // 关联性
        while (reader->Read()) {
            
        }
    }
};
