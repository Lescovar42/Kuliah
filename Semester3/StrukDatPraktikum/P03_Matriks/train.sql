-- Supertype RollingStock
CREATE TABLE RollingStock (
  rolling_id      SERIAL PRIMARY KEY,
  serial_no       VARCHAR(50) UNIQUE NOT NULL,
  manufacturer    VARCHAR(100),
  built_year      SMALLINT,
  status          VARCHAR(20) NOT NULL CHECK (status IN ('active','maintenance','decommissioned'))
);

-- Subtype PassengerTrain
CREATE TABLE PassengerTrain (
  rolling_id      INT PRIMARY KEY,          -- PK and FK to RollingStock
  capacity        INT NOT NULL,
  car_count       INT,
  service_type    VARCHAR(30),              -- e.g. 'commuter', 'limited express'
  FOREIGN KEY (rolling_id) REFERENCES RollingStock(rolling_id) ON DELETE CASCADE
);

-- Subtype Shinkansen
CREATE TABLE Shinkansen (
  rolling_id      INT PRIMARY KEY,
  max_speed       INT,                      -- km/h
  platform_type   VARCHAR(30),
  FOREIGN KEY (rolling_id) REFERENCES RollingStock(rolling_id) ON DELETE CASCADE
);

-- Subtype MaintenanceTrain
CREATE TABLE MaintenanceTrain (
  rolling_id      INT PRIMARY KEY,
  maintenance_type VARCHAR(50),
  equipment_list  TEXT,
  FOREIGN KEY (rolling_id) REFERENCES RollingStock(rolling_id) ON DELETE CASCADE
);

-- Crew supertype
CREATE TABLE Crew (
  crew_id     SERIAL PRIMARY KEY,
  name        VARCHAR(100) NOT NULL,
  role_type   VARCHAR(20) NOT NULL CHECK(role_type IN ('driver','conductor','engineer','other'))
);

-- Crew subtype Driver
CREATE TABLE Driver (
  crew_id     INT PRIMARY KEY,
  license_no  VARCHAR(50) NOT NULL,
  license_class VARCHAR(50),
  FOREIGN KEY (crew_id) REFERENCES Crew(crew_id) ON DELETE CASCADE
);

-- Crew subtype Conductor (contoh)
CREATE TABLE Conductor (
  crew_id     INT PRIMARY KEY,
  certification VARCHAR(100),
  FOREIGN KEY (crew_id) REFERENCES Crew(crew_id) ON DELETE CASCADE
);

-- Service table (rute/jadwal)
CREATE TABLE Service (
  service_id   SERIAL PRIMARY KEY,
  name         VARCHAR(100),
  route        VARCHAR(200),
  departure_time TIME
);

-- Assignment linking train, service, crew (many assignments over time)
CREATE TABLE TrainAssignment (
  assign_id    SERIAL PRIMARY KEY,
  service_id   INT NOT NULL REFERENCES Service(service_id),
  rolling_id   INT NOT NULL REFERENCES RollingStock(rolling_id),
  crew_id      INT NOT NULL REFERENCES Crew(crew_id),
  assigned_date DATE NOT NULL,
  UNIQUE(service_id, rolling_id, assigned_date) -- optional: prevent duplicate assignment for same date
);
