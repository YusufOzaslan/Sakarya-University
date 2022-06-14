--
-- PostgreSQL database dump
--

-- Dumped from database version 13.4
-- Dumped by pg_dump version 14.0

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- Name: KullaniciHesabi; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."KullaniciHesabi" (
    id integer NOT NULL,
    "kullaniciAdi" character varying(40) NOT NULL,
    sifre character varying
);


ALTER TABLE public."KullaniciHesabi" OWNER TO postgres;

--
-- Name: KullaniciHesabi_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."KullaniciHesabi_id_seq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."KullaniciHesabi_id_seq" OWNER TO postgres;

--
-- Name: KullaniciHesabi_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."KullaniciHesabi_id_seq" OWNED BY public."KullaniciHesabi".id;


--
-- Name: KullaniciHesabi_id_seq1; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."KullaniciHesabi_id_seq1"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."KullaniciHesabi_id_seq1" OWNER TO postgres;

--
-- Name: KullaniciHesabi_id_seq1; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."KullaniciHesabi_id_seq1" OWNED BY public."KullaniciHesabi".id;


--
-- Name: KullaniciHesabi id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."KullaniciHesabi" ALTER COLUMN id SET DEFAULT nextval('public."KullaniciHesabi_id_seq1"'::regclass);


--
-- Data for Name: KullaniciHesabi; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."KullaniciHesabi" VALUES
	(1, 'yusuf', '123'),
	(2, 'ozaslan', '456');


--
-- Name: KullaniciHesabi_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."KullaniciHesabi_id_seq"', 1, false);


--
-- Name: KullaniciHesabi_id_seq1; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."KullaniciHesabi_id_seq1"', 2, true);


--
-- PostgreSQL database dump complete
--

