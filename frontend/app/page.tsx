import { Card } from './components/Button';
import { FaUserGraduate, FaChalkboardTeacher, FaBuilding } from 'react-icons/fa';

export default function Home() {
  return (
    <div className="flex flex-col items-center justify-center min-h-screen bg-white text-black p-6">
      <h1 className="text-7xl font-bold mb-14">LkCIn</h1>
      <div className="grid grid-cols-1 md:grid-cols-3 gap-6 w-full max-w-3xl">
        <Card label="Sou Aluno" route="/login/aluno" icon={<FaUserGraduate />} />
        <Card label="Sou Professor" route="/login/professor" icon={<FaChalkboardTeacher />} />
        <Card label="Sou Empresa" route="/login/empresa" icon={<FaBuilding />} />
      </div>
    </div>
  );
}